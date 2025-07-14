# Mod de Prueba - Sistema de Spawn para DayZ

## Descripción
Este mod crea un sistema de selección de spawn que se activa cuando un jugador respawnea. El servidor envía una señal RPC al cliente para mostrar un menú, el jugador selecciona una ubicación, y el servidor lo teletransporta.

## Correcciones Aplicadas

### 1. Error RPC Principal (SOLUCIONADO)
**Error Original:**
```
Types Param1<vector> and 'array<@Param>' are unrelated
```

**Solución:** Sistema RPC nativo de DayZ con IDs numéricos y Event_OnRPC:
```c
// ANTES (Problemático):
auto params = new Param1<vector>(spawnPos);
auto rpc_params = new array<Param>();
rpc_params.Insert(params);
GetGame().RPC(null, moddeprueba_RPCs.RPC_TELEPORT_PLAYER, rpc_params, true);

// DESPUÉS (Correcto):
auto params = new Param1<vector>(spawnPos);
GetGame().RPCSingleParam(null, moddeprueba_RPCs.RPC_TELEPORT_PLAYER, params, true);
```

### 2. Error Event_OnRPC Variable (SOLUCIONADO)
**Error:**
```
Can't find variable 'Event_OnRPC'
```

**Solución:** Usar override void OnRPC() en lugar de Event_OnRPC.Insert():
```c
// ANTES (Error):
void MissionServer() {
    GetGame().Event_OnRPC.Insert(this.HandleRPC);
}

// DESPUÉS (Correcto):
override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
    super.OnRPC(sender, target, rpc_type, ctx);
    // Manejar RPCs específicos aquí
}
```

### 3. Sistema RPC Nativo Implementado
- **override void OnRPC()**: Método correcto para manejar RPCs en MissionServer y MissionGameplay
- **GetGame().RPCSingleParam()**: Envío de RPCs con sintaxis nativa
- **IDs numéricos únicos**: Usando enum con valores específicos (12345, 12346)
- **super.OnRPC()**: Llamada a la clase base para mantener compatibilidad

### 4. Arquitectura Final
- **Cliente (UI)**: GetGame().RPCSingleParam() para enviar al servidor
- **Servidor**: override void OnRPC() para recibir del cliente
- **Cliente (Mission)**: override void OnRPC() para recibir del servidor
- **Flujo completo**: Respawn → Servidor envía RPC → Cliente abre menú → Cliente envía posición → Servidor teletransporta

### 3. Validaciones Adicionales
- Verificación de IsServer() e IsClient() en las funciones RPC
- Validación de lectura de parámetros antes de procesarlos
- Verificación de existencia del jugador antes de teletransporte

## Estructura del Mod
```
moddeprueba/
├── config.cpp                                 # Configuración del mod
├── gui/
│   └── spawn_menu.layout                     # Layout de la interfaz
└── scripts/
    ├── 3_Game/
    │   └── moddeprueba_RPCTypes.c            # Definición de tipos RPC
    ├── 4_World/
    │   └── moddeprueba_SpawnMenu.c           # Interfaz del menú
    └── 5_Mission/
        ├── moddeprueba_MissionServer.c       # Lógica del servidor
        └── moddeprueba_MissionGameplay.c     # Lógica del cliente
```

## Funcionamiento
1. **Respawn del Jugador:** Cuando un jugador respawnea, se trigger OnClientRespawnEvent
2. **Envío de RPC:** El servidor envía RPC_OPEN_MENU al cliente
3. **Mostrar Menú:** El cliente recibe el RPC y muestra la interfaz de spawn
4. **Selección:** El jugador hace clic en un botón de ubicación
5. **Envío de Posición:** El cliente envía RPC_TELEPORT_PLAYER con la posición
6. **Teletransporte:** El servidor recibe la posición y teletransporta al jugador

## Ubicaciones de Spawn
- **Elektrozavodsk:** 11736 23 12488
- **Cherno:** 2188 23 5447
- **Berezino:** 12250 10 9550

## Testing
Para probar el mod:
1. Instala el mod en tu servidor DayZ
2. Mata a tu personaje para activar el respawn
3. Debería aparecer el menú de selección automáticamente
4. Selecciona una ubicación y confirma el teletransporte

## Notas Técnicas
- Compatible con DayZ 1.19+
- Usa el sistema RPC nativo de DayZ
- Interfaz creada con el sistema Widget de DayZ
- Sigue el orden de carga estándar de scripts (3_Game → 4_World → 5_Mission)