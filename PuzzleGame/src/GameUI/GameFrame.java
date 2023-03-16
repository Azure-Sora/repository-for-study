package GameUI;

import javax.swing.*;

public class GameFrame extends JFrame {
    public GameFrame() {
        intiFrame();
        intiMenuBar();

        this.setVisible(true);
    }

    private void intiMenuBar() {
        JMenuBar jmb = new JMenuBar();
        //游戏菜单
        JMenu gameOperateMenu = new JMenu("游戏");
        JMenuItem exitGameItem = new JMenuItem("退出游戏");
        gameOperateMenu.add(exitGameItem);
        jmb.add(gameOperateMenu);
        //关于菜单
        JMenu aboutMenu = new JMenu("关于");
        jmb.add(aboutMenu);

        this.setJMenuBar(jmb);
    }

    private void intiFrame() {
        this.setSize(600,650);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Puzzle Game v0.1");
        this.setIconImage(new ImageIcon("resource/testIcon.png").getImage());

    }
}
