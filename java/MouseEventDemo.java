import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseEventDemo extends JFrame implements MouseListener {
    private JLabel statusLabel;

    public MouseEventDemo() {
        super("Mouse Event Demo");
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.addMouseListener(this);

        statusLabel = new JLabel("Mouse status: ");
        panel.add(statusLabel, BorderLayout.SOUTH);

        add(panel);
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        statusLabel.setText("Mouse clicked");
        getContentPane().setBackground(Color.RED);
    }

    public void mouseEntered(MouseEvent e) {
        statusLabel.setText("Mouse entered");
        getContentPane().setBackground(Color.GREEN);
    }

    public void mouseExited(MouseEvent e) {
        statusLabel.setText("Mouse exited");
        getContentPane().setBackground(Color.BLUE);
    }

    public void mousePressed(MouseEvent e) {
        statusLabel.setText("Mouse pressed");
        getContentPane().setBackground(Color.YELLOW);
    }

    public void mouseReleased(MouseEvent e) {
        statusLabel.setText("Mouse released");
        getContentPane().setBackground(Color.ORANGE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new MouseEventDemo();
            }
        });
    }
}
