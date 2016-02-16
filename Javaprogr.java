package pack;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Reddak implements ActionListener  {
	JTextField  Redak1;
	JTextField  Redak2;
	JTextField  Redak3;
	Reddak() {
	JFrame Pole1=new JFrame("Sum");
	Pole1.getContentPane().setLayout(new FlowLayout());
	Pole1.setSize(570,180);
	Pole1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	JLabel poltext1=new JLabel("Enter 1 number:");
	JLabel poltext2=new JLabel("Enter 2 number:");
	JLabel poltext3=new JLabel("Result:");
	Redak1=new  JTextField(40);
	Redak2=new  JTextField(40);
	Redak3=new  JTextField(40);
	Redak1.setActionCommand("Sum");
	Redak1.addActionListener(this);
	Pole1.getContentPane().add(poltext1);
	Pole1.getContentPane().add(Redak1);
	Pole1.getContentPane().add(poltext2);
	Pole1.getContentPane().add(Redak2);
	Pole1.getContentPane().add(poltext3);
	Pole1.getContentPane().add(Redak3);
	JButton knopVvod=new JButton("Sum");
	JButton knopSbros=new JButton("Clean");
	knopVvod.addActionListener(this);
	knopSbros.addActionListener(this);
	Pole1.getContentPane().add((knopSbros));
	Pole1.getContentPane().add((knopVvod)); 
	Pole1.setVisible(true);
	}

	public void actionPerformed(ActionEvent sob){	 
		if (sob.getActionCommand().equals("Sum"))			
	{
		 StringBuffer str=new StringBuffer(Redak2.getText());
			String s = Redak1.getText();
			String e = Redak2.getText();
			int d = Integer.valueOf(s);
			int d1 = Integer.valueOf(e);
			boolean isBinary=true;
	        while (d != 0) {
	            if (d % 10 > 7) {
	                 isBinary=false;	  
	            }
	            d = d / 10;
	        }
	        while (d1 != 0) {
	            if (d1 % 10 > 7) {
	                 isBinary=false;  
	            }
	            d1 = d1 / 10;
	        }   	        
			if (isBinary==false){
			
				Redak3.setText("It's not octal number system");
			}
			else {
				int z=Integer.parseInt(s,8);
				int z1=Integer.parseInt(e,8);
				int zz=z+z1;
			    String st = Double.toString(zz);
				Redak3.setText(st);
			}	    
	}

	else {
	Redak1.setText("");
	Redak2.setText("");
	Redak3.setText("");
	}}

	public static void main(String args[]){
	    SwingUtilities.invokeLater(new Runnable(){
	public  void run(){
	  new Reddak();
	}});}}