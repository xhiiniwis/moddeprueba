class moddeprueba_SpawnMenu extends UIScriptedMenu 
{
    private ButtonWidget m_SpawnButton1, m_SpawnButton2, m_SpawnButton3;
    
    override Widget Init() 
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("moddeprueba/gui/spawn_menu.layout");
        m_SpawnButton1 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SpawnButton1"));
        m_SpawnButton2 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SpawnButton2"));
        m_SpawnButton3 = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SpawnButton3"));
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
                break;
            case m_SpawnButton2: 
                spawnPos = "2188 23 5447";  
                break;
            case m_SpawnButton3: 
                spawnPos = "12250 10 9550"; 
                break;
        }
        
        if (spawnPos != "0 0 0") 
        {
            // CORRECCIÓN: Usar GetGame().RPCSingleParam() con enum RPC ID
            auto params = new Param1<vector>(spawnPos);
            GetGame().RPCSingleParam(null, moddeprueba_RPCs.RPC_TELEPORT_PLAYER, params, true);
            Close();
        }
        return false;
    }
}