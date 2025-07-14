class CfgPatches 
{
    class moddeprueba 
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.28;
        requiredAddons[] = {"DZ_Data", "DZ_Scripts"};
        version = "1.0";
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