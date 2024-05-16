import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseClickNameDisplay extends JFrame implements MouseListener {
    private JLabel nameLabel;

    public MouseClickNameDisplay() {
        super("Mouse Click Name Display");

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.addMouseListener(this);

        nameLabel = new JLabel();
        panel.add(nameLabel, BorderLayout.CENTER);

        add(panel);
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        nameLabel.setText("Kunal Dua");
    }

    public void mouseEntered(MouseEvent e) {}

    public void mouseExited(MouseEvent e) {}

    public void mousePressed(MouseEvent e) {}

    public void mouseReleased(MouseEvent e) {}

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new MouseClickNameDisplay();
            }
        });
    }
}
