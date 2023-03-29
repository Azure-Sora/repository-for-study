package GameUI;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Random;

public class GameFrame extends JFrame {
    private int[] pictureOrder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    private int nowIndex = 0;
    nextPicture np = new nextPicture();

    public GameFrame() {
        intiFrame();
        intiMenuBar();
        intiPicture();
        this.setVisible(true);
    }


    private class picturePiece extends JButton implements MouseListener {
        private int index;
        private int x;
        private int y;
        private boolean isFilled = false;

        public picturePiece(int index) {
            x = index % 3 * 200 + 50;
            y = index / 3 * 200 + 50;
            this.setBounds(x, y, 200, 200);
            this.index = index;
            this.setIcon(new ImageIcon("src/resources/buttonPictures/normal.png"));
            this.addMouseListener(this);
            this.setBorder(new BevelBorder(BevelBorder.RAISED));

            GameFrame.this.add(this);
        }


        @Override
        public void mouseClicked(MouseEvent e) {
            if (index == pictureOrder[nowIndex] - 1) {
                this.setIcon(new ImageIcon("src/resources/pictureLong/_0" + pictureOrder[nowIndex] + ".jpg"));
                this.isFilled = true;
                if (nowIndex < 8) {
                    nowIndex++;
                }
                np.showNext();
            } else {
                this.setIcon(new ImageIcon("src/resources/buttonPictures/answerWrong.png"));
            }
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {
            if (!isFilled) {
                this.setIcon(new ImageIcon("src/resources/buttonPictures/mouseEntered.png"));
            }
        }

        @Override
        public void mouseExited(MouseEvent e) {
            if (!isFilled) {
                this.setIcon(new ImageIcon("src/resources/buttonPictures/normal.png"));
            }
        }
    }

    private class nextPicture extends JLabel {
        public nextPicture() {
            //创建下一张图片
            this.setBounds(700, 250, 200, 200);
            this.setBorder(new BevelBorder(BevelBorder.RAISED));
        }

        private void showUI() {
            GameFrame.this.add(this);
        }

        private void showNext() {
            this.setIcon(new ImageIcon("src/resources/pictureLong/_0" + pictureOrder[nowIndex] + ".jpg"));
        }
    }

    private void intiPicture() {
        ArrayList<picturePiece> pics = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            pics.add(new picturePiece(i));
        }

        Random rd = new Random();
        for (int i = 0; i < 9; i++) {
            int rdIndex = rd.nextInt(9);
            int temp = pictureOrder[i];
            pictureOrder[i] = pictureOrder[rdIndex];
            pictureOrder[rdIndex] = temp;
        }


        //创建文字
        JLabel textNEXT = new JLabel("下一张");
        textNEXT.setBounds(750, 200, 100, 50);
        textNEXT.setFont(new Font("黑体", Font.BOLD, 30));
        this.add(textNEXT);

        np.showNext();
        np.showUI();
    }

    private void intiMenuBar() {
        JMenuBar jmb = new JMenuBar();

        //游戏菜单
        JMenu gameOperateMenu = new JMenu("游戏");
        JMenuItem exitGameItem = new JMenuItem("退出游戏");
        exitGameItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        gameOperateMenu.add(exitGameItem);
        jmb.add(gameOperateMenu);

        //关于菜单
        JMenu aboutMenu = new JMenu("关于");
        JMenuItem aboutMe = new JMenuItem("关于");
        aboutMenu.add(aboutMe);
        aboutMe.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JLabel aboutMe = new JLabel();
                aboutMe.setBounds(0, 0, 642, 642);
                aboutMe.setIcon(new ImageIcon("src/resources/mika.png"));
                JDialog dialog = new JDialog();
                dialog.setSize(670, 700);
                dialog.setAlwaysOnTop(true);
                dialog.setLocationRelativeTo(null);
                dialog.add(aboutMe);
                dialog.setModal(true);
                dialog.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
                dialog.setVisible(true);
            }
        });
        jmb.add(aboutMenu);


        this.setJMenuBar(jmb);
    }

    private void intiFrame() {
        this.setSize(950, 850);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setLayout(null);
        this.setTitle("Puzzle Game v0.1");
        this.setIconImage(new ImageIcon("src/resources/testIcon.png").getImage());

    }
}
