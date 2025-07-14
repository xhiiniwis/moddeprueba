# Guía de Instalación del Mod en el Servidor

## Pasos para Instalar el Mod:

### 1. Copiar el Mod
- Copia la carpeta completa `moddeprueba` al directorio de mods del servidor
- Ubicación típica: `DayZServer/mods/moddeprueba/`

### 2. Configurar el Servidor
Añade el mod a la línea de comandos del servidor:
```
-mod=moddeprueba
```

O en el archivo serverDZ.cfg:
```
template="DayZ";
hostname="Mi Servidor con Mod de Spawn";
mods[] = {"moddeprueba"};
```

### 3. Verificar Carga del Mod
Revisa los logs del servidor para confirmar que el mod se cargó:
```
[SCRIPT] Loading script module: "moddeprueba"
[SCRIPT] Script module "moddeprueba" loaded successfully
```

### 4. Estructura del Mod Completa
```
moddeprueba/
├── Addons/                         # Carpeta para compatibilidad
├── Keys/                           # Claves del mod
│   └── moddeprueba.bikey
├── gui/                            # Archivos de interfaz
│   └── spawn_menu.layout
├── scripts/                        # Scripts del mod
│   ├── 3_Game/
│   │   └── moddeprueba_RPCTypes.c
│   ├── 4_World/
│   │   └── moddeprueba_SpawnMenu.c
│   └── 5_Mission/
│       ├── moddeprueba_MissionGameplay.c
│       └── moddeprueba_MissionServer.c
├── config.cpp                      # Configuración principal
├── mod.cpp                         # Metadatos del mod
└── meta.cpp                        # Metadatos adicionales
```

### 5. Solución de Problemas

#### El mod no aparece en los logs:
- Verifica que la carpeta esté en la ubicación correcta
- Revisa que el config.cpp no tenga errores de sintaxis
- Asegúrate de que el servidor tenga permisos de lectura

#### El mod se carga pero no funciona:
- Revisa los logs del servidor para errores de script
- Verifica que todas las dependencias estén instaladas
- Confirma que no haya conflictos con otros mods

#### Errores de RPC:
- Verifica que los IDs de RPC sean únicos
- Revisa que las clases Mission estén correctamente heredadas
- Confirma que los parámetros RPC sean válidos

### 6. Testing
1. Reinicia el servidor
2. Conéctate al servidor
3. Mata tu personaje para activar el respawn
4. Verifica que aparezca el menú de selección de spawn
5. Selecciona una ubicación y confirma el teletransporte

## Nota Importante
Este mod requiere DayZ 1.19+ y es compatible con la versión 2025 de Enforce Script.