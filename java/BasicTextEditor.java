import javax.swing.*;
import javax.swing.text.AttributeSet;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class BasicTextEditor extends JFrame {
    private JTextPane textPane;
    private JComboBox<String> fontComboBox;
    private JComboBox<Integer> fontSizeComboBox;
    private JToggleButton boldButton;
    private JToggleButton italicButton;
    private JToggleButton underlineButton;
    private JComboBox<String> alignmentComboBox;

    public BasicTextEditor() {
        super("Basic Text Editor");

        textPane = new JTextPane();
        textPane.setPreferredSize(new Dimension(600, 400));

        String[] fonts = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        fontComboBox = new JComboBox<>(fonts);

        Integer[] fontSizes = {8, 10, 12, 14, 16, 18, 20, 22, 24};
        fontSizeComboBox = new JComboBox<>(fontSizes);

        boldButton = new JToggleButton("B");
        italicButton = new JToggleButton("I");
        underlineButton = new JToggleButton("U");

        String[] alignments = {"Left", "Center", "Right"};
        alignmentComboBox = new JComboBox<>(alignments);

        JToolBar toolBar = new JToolBar();
        toolBar.setFloatable(false);
        toolBar.add(fontComboBox);
        toolBar.add(fontSizeComboBox);
        toolBar.addSeparator();
        toolBar.add(boldButton);
        toolBar.add(italicButton);
        toolBar.add(underlineButton);
        toolBar.addSeparator();
        toolBar.add(alignmentComboBox);

        fontComboBox.addActionListener(new FontComboBoxListener());
        fontSizeComboBox.addActionListener(new FontSizeComboBoxListener());
        boldButton.addActionListener(new BoldButtonListener());
        italicButton.addActionListener(new ItalicButtonListener());
        underlineButton.addActionListener(new UnderlineButtonListener());
        alignmentComboBox.addItemListener(new AlignmentComboBoxListener());

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(toolBar, BorderLayout.NORTH);
        getContentPane().add(new JScrollPane(textPane), BorderLayout.CENTER);

        pack();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    class FontComboBoxListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String fontName = (String) fontComboBox.getSelectedItem();
            textPane.setFont(new Font(fontName, Font.PLAIN, textPane.getFont().getSize()));
        }
    }

    class FontSizeComboBoxListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            int fontSize = (int) fontSizeComboBox.getSelectedItem();
            textPane.setFont(textPane.getFont().deriveFont((float) fontSize));
        }
    }

    class BoldButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            AttributeSet attrs = textPane.getInputAttributes();
            boolean bold = StyleConstants.isBold(attrs);
            SimpleAttributeSet attrsNew = new SimpleAttributeSet();
            StyleConstants.setBold(attrsNew, !bold);
            setCharacterAttributes(attrsNew);
        }
    }

    class ItalicButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            AttributeSet attrs = textPane.getInputAttributes();
            boolean italic = StyleConstants.isItalic(attrs);
            SimpleAttributeSet attrsNew = new SimpleAttributeSet();
            StyleConstants.setItalic(attrsNew, !italic);
            setCharacterAttributes(attrsNew);
        }
    }

    class UnderlineButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            AttributeSet attrs = textPane.getInputAttributes();
            boolean underline = StyleConstants.isUnderline(attrs);
            SimpleAttributeSet attrsNew = new SimpleAttributeSet();
            StyleConstants.setUnderline(attrsNew, !underline);
            setCharacterAttributes(attrsNew);
        }
    }

    class AlignmentComboBoxListener implements ItemListener {
        public void itemStateChanged(ItemEvent e) {
            String alignment = (String) alignmentComboBox.getSelectedItem();
            int align = switch (alignment) {
                case "Left" -> StyleConstants.ALIGN_LEFT;
                case "Center" -> StyleConstants.ALIGN_CENTER;
                case "Right" -> StyleConstants.ALIGN_RIGHT;
                default -> StyleConstants.ALIGN_LEFT;
            };
            SimpleAttributeSet attrs = new SimpleAttributeSet();
            StyleConstants.setAlignment(attrs, align);
            setParagraphAttributes(attrs);
        }
    }

    private void setCharacterAttributes(AttributeSet attrs) {
        StyledDocument doc = textPane.getStyledDocument();
        doc.setCharacterAttributes(textPane.getSelectionStart(), textPane.getSelectionEnd() - textPane.getSelectionStart(), attrs, false);
    }

    private void setParagraphAttributes(AttributeSet attrs) {
        StyledDocument doc = textPane.getStyledDocument();
        doc.setParagraphAttributes(textPane.getSelectionStart(), textPane.getSelectionEnd() - textPane.getSelectionStart(), attrs, false);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(BasicTextEditor::new);
    }
}
