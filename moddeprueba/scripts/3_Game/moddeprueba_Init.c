// Inicialización del mod moddeprueba para DayZ 2025
// Este archivo se asegura de que el mod se cargue correctamente

class moddeprueba_Init
{
    void moddeprueba_Init()
    {
        Print("[ModDePrueba] Mod inicializado correctamente");
        Print("[ModDePrueba] Version: 1.0.0 - DayZ 2025 Compatible");
        Print("[ModDePrueba] Sistema de spawn activo");
        Print("[ModDePrueba] Presiona F1 para abrir el menú de spawn");
    }
}

// Instanciar la clase para inicializar el mod - DayZ 2025 compatible
static ref moddeprueba_Init g_moddeprueba_instance = new moddeprueba_Init();