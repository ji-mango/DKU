package ll;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class moveString extends JFrame{
	private JLabel st=new JLabel("Love Java");
	
	public moveString() {
	setTitle("Letf키로 문자열 이동");
	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	Container c=getContentPane();
	c.setLayout(new FlowLayout());
	st.setSize(100,50);
	st.setLocation(30,30);
	c.add(st);
	c.addKeyListener(new MyKeyListener());
	
	setSize(500,350);
	setVisible(true);
	
	c.setFocusable(true);
	c.requestFocus();
	}	
	
	class MyKeyListener extends KeyAdapter {
		String return_str=st.getText();
		public void keyPressed(KeyEvent e) {
			if(e.getKeyCode()==KeyEvent.VK_LEFT)
			{	
				return_str=return_str.substring(1)+return_str.substring(0,1);
				st.setText(return_str);
			}
		}
		public void keyReleased(KeyEvent e) {}
		public void keyTyped(KeyEvent e) {}
	}
	
	public static void main(String[] args) {
		new moveString();
	}
}
	