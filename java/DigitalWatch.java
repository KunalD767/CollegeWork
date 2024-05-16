import javax.swing.*;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DigitalWatch extends JFrame implements Runnable {
    private JLabel timeLabel;

    public DigitalWatch() {
        super("Digital Watch");
        timeLabel = new JLabel("", JLabel.CENTER);
        timeLabel.setFont(new Font("Arial", Font.PLAIN, 48));

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(timeLabel, BorderLayout.CENTER);

        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        Thread thread = new Thread(this);
        thread.start();
    }

    @Override
    public void run() {
        while (true) {
            updateTime();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private void updateTime() {
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
        Date now = new Date();
        timeLabel.setText(sdf.format(now));
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(DigitalWatch::new);
    }
}
