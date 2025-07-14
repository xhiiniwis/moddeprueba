// Sistema simplificado para DayZ 1.28
modded class MissionServer 
{
    void MissionServer()
    {
        Print("[ModDePrueba] MissionServer inicializado correctamente - DayZ 1.28");
    }
    
    override void OnClientRespawnEvent(PlayerIdentity identity, Man player) 
    {
        super.OnClientRespawnEvent(identity, player);
        Print("[ModDePrueba] Jugador respawneado: " + identity.GetName());
        
        // Mostrar menú de spawn automáticamente al respawn
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ShowSpawnMenuForPlayer, 2000, false, identity);
    }
    
    void ShowSpawnMenuForPlayer(PlayerIdentity identity)
    {
        Print("[ModDePrueba] Intentando mostrar menú de spawn para: " + identity.GetName());
        // El menú se mostrará automáticamente en el cliente
    }
}