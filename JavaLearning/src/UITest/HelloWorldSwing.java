package UITest;
import javax.swing.*;
public class HelloWorldSwing extends JFrame{
    public HelloWorldSwing() {
        super("Hello World"); // 设置窗口标题
        /*JButton button = new JButton("test");
        button.setBounds(50, 50, 100, 50);
        add(button);*/
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 设置关闭行为
/*        pack(); // 自动调整大小*/
        setSize(400, 300); // 设置窗口大小
        setVisible(true); // 设置可见性

    }
    public void showHelloWorld(){
        JLabel label = new JLabel("Hello World"); // 创建标签组件
        this.add(label); // 将标签添加到窗口中
    }

    public static void main(String[] args) {
        HelloWorldSwing test = new HelloWorldSwing(); // 创建并显示窗口对象
        test.showHelloWorld();
    }
}
