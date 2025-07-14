// Utilidades para el mod moddeprueba - DayZ 1.28
class moddeprueba_Utils
{
    // Función para teletransportar jugador - DayZ 1.28
    static void TeleportPlayer(Object player, vector position)
    {
        if (!player) 
            return;
            
        if (player.IsInherited(Man))
        {
            Man playerMan = Man.Cast(player);
            if (playerMan)
            {
                playerMan.SetPosition(position);
                Print("[ModDePrueba] Jugador teletransportado a: " + position.ToString());
            }
        }
    }
    
    // Función para verificar si el mod está activo
    static bool IsModActive()
    {
        return true;
    }
    
    // Función para obtener el jugador actual - DayZ 1.28
    static Object GetCurrentPlayer()
    {
        return GetGame().GetPlayer();
    }
}