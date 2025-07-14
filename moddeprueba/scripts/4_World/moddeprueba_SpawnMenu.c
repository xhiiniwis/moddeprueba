class moddeprueba_SpawnMenu extends UIScriptedMenu 
{
    private ButtonWidget m_SpawnButton1, m_SpawnButton2, m_SpawnButton3;
    
    // Función estática para mostrar el menú
    static void ShowSpawnMenu()
    {
        if (!GetGame().IsClient()) 
            return;
            
        if (GetGame().GetUIManager().GetMenu() == NULL) 
        {
            GetGame().GetUIManager().ShowScriptedMenu(new moddeprueba_SpawnMenu(), NULL);
            Print("[ModDePrueba] Menú de spawn mostrado");
        }
    }
    
    override Widget Init() 
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("moddeprueba/gui/spawn_menu.layout");
        m_SpawnButton1 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SpawnButton1"));
        m_SpawnButton2 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SpawnButton2"));
        m_SpawnButton3 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SpawnButton3"));
        
        Print("[ModDePrueba] SpawnMenu inicializado");
        return layoutRoot;
    }
    
    override bool OnClick(Widget w, int x, int y, int button) 
    {
        super.OnClick(w, x, y, button);
        vector spawnPos = "0 0 0";
        
        switch(w) 
        {
            case m_SpawnButton1: 
                spawnPos = "11736 23 12488"; 
                Print("[ModDePrueba] Seleccionado: Elektrozavodsk");
                break;
            case m_SpawnButton2: 
                spawnPos = "2188 23 5447";  
                Print("[ModDePrueba] Seleccionado: Cherno");
                break;
            case m_SpawnButton3: 
                spawnPos = "12250 10 9550"; 
                Print("[ModDePrueba] Seleccionado: Berezino");
                break;
        }
        
        if (spawnPos != "0 0 0") 
        {
            // Teletransportar usando Object para evitar problemas de tipo
            Object player = moddeprueba_Utils.GetCurrentPlayer();
            if (player) 
            {
                moddeprueba_Utils.TeleportPlayer(player, spawnPos);
            }
            else
            {
                Print("[ModDePrueba] Error: No se pudo obtener el jugador");
            }
            Close();
        }
        return false;
    }
}