class CfgPatches 
{
    class moddeprueba 
    {
        requiredAddons[] = {"DZ_Data"};
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        version = 1.0;
        author = "ModDePrueba";
    };
};

class CfgMods 
{
    class moddeprueba 
    {
        dir = "moddeprueba";
        name = "Mod de Prueba - Sistema de Spawn";
        credits = "ModDePrueba";
        version = "1.0.0";
        author = "ModDePrueba";
        authorID = "0";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        class defs 
        {
            class gameScriptModule 
            {
                value = "";
                files[] = {"moddeprueba/scripts/3_Game"};
            };
            class worldScriptModule 
            {
                value = "";
                files[] = {"moddeprueba/scripts/4_World"};
            };
            class missionScriptModule 
            {
                value = "";
                files[] = {"moddeprueba/scripts/5_Mission"};
            };
        };
    };
};