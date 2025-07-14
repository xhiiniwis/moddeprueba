modded class MissionServer 
{
    override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player) 
    {
        super.OnClientRespawnEvent(identity, player);
        // Enviar RPC para abrir menú usando ID numérico
        GetGame().RPCSingleParam(identity, moddeprueba_RPCs.RPC_OPEN_MENU, null, false);
    }
    
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, target, rpc_type, ctx);
        
        switch (rpc_type)
        {
            case moddeprueba_RPCs.RPC_TELEPORT_PLAYER:
                HandleTeleportRPC(sender, ctx);
                break;
        }
    }
    
    void HandleTeleportRPC(PlayerIdentity sender, ParamsReadContext ctx) 
    {
        if (!GetGame().IsServer()) 
            return;
            
        Param1<vector> data;
        if (!ctx.Read(data)) 
            return;
            
        PlayerBase player = PlayerBase.GetPlayerByUID(sender.GetId());
        if (player) 
        {
            player.SetPosition(data.param1);
            Print("[ModDePrueba] Jugador teletransportado a: " + data.param1.ToString());
        }
    }
}