modded class MissionGameplay 
{
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, target, rpc_type, ctx);
        
        switch (rpc_type)
        {
            case moddeprueba_RPCs.RPC_OPEN_MENU:
                HandleOpenMenuRPC();
                break;
        }
    }
    
    void HandleOpenMenuRPC() 
    {
        if (!GetGame().IsClient()) 
            return;
            
        if (GetGame().GetUIManager().GetMenu() == NULL) 
        {
            GetGame().GetUIManager().ShowScriptedMenu(new moddeprueba_SpawnMenu(), NULL);
            Print("[ModDePrueba] Menú de spawn abierto");
        }
    }
}