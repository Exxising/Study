import javax.swing.*;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

class GameFrame extends JFrame 
{
	public GameFrame() 
	{
		setTitle("Puzzle Game");
		setSize(600, 600);
		setVisible(true);
	}
}

public class GameManager 
{
	final int GRID_SIZE = 8;
	JButton[][] buttons = new JButton[GRID_SIZE][GRID_SIZE];
	Piece[][] gameBoard;
	boolean[][] checkCanPlaced;
	Piece currentPiece;
	Random rand = new Random();
	JButton pieceButton;
	JPanel boardPanel;
	boolean gameEnd;
	GameFrame frame;
	int score;
	
	private static String[] canPlacePieces = {"Queen", "Bishop", "Rook"};
	
	public GameManager() { }
	
	public void InitializeGame() 
	{
		frame = new GameFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout()); // 메인 게임판, 뽑기 버튼을 위해 BorderLayout으로 지정

        JPanel drawPanel = new JPanel();
        
        pieceButton = new JButton("랜덤 말 뽑기");
        pieceButton.addActionListener(new PieceButtonListener());
        drawPanel.add(pieceButton); // 말 뽑기 버튼 담을 패널

        boardPanel = new JPanel(new GridLayout(GRID_SIZE, GRID_SIZE));
        InitializeBoard(boardPanel, true); // 최초 실행시 true, board 의 상태를 초기화
        
        // UI 설정
        frame.add(boardPanel, BorderLayout.CENTER);
        frame.add(drawPanel, BorderLayout.SOUTH);

        frame.pack(); // Preferred 사이즈에 맞게 윈도우 크기 지정
        frame.setVisible(true);
	}
	
	private void RestartGame() 
	{
		InitializeBoard(boardPanel, false);
	}
	
	private void CheckGameFinished() 
	{
		for(int x = 0; x<GRID_SIZE; x++) 
		{
			for(int y = 0; y<GRID_SIZE; y++) 
			{	
				// 게임이 끝나지 않았음
				if(gameBoard[x][y] == null && checkCanPlaced[x][y] == true) return;
			}
		}
		
		// 전부 체크해보고 놓을 수 있는 공간이 없으면 종료
		JOptionPane.showMessageDialog(null, String.format("게임 종료, 최종 스코어 : %d", score));
		frame.setTitle(String.format("Puzzle Game | 최종 스코어 : %d", score));
		return;
	}
	
	private void InitializeBoard(JPanel boardPanel, boolean init) 
	{
		gameBoard 			= new Piece[GRID_SIZE][GRID_SIZE];
		checkCanPlaced 		= new boolean[GRID_SIZE][GRID_SIZE];
		currentPiece 		= null;
		gameEnd				= false;
		score				= 0;
		pieceButton.setText("랜덤 말 뽑기");
		frame.setTitle("Puzzle Game");
		
		// 게임이 처음 시작할 때만 버튼을 추가하는 것
		if(init == true) 
		{
			for (int row = 0; row < GRID_SIZE; row++) 
	        {
	            for (int col = 0; col < GRID_SIZE; col++) 
	            {
	                buttons[row][col] = new JButton();
	                buttons[row][col].setPreferredSize(new Dimension(80, 80));	// 버튼 폭과 넓이 지정
	                buttons[row][col].setBackground((row + col) % 2 == 0 ? Color.WHITE : Color.GRAY);
	                buttons[row][col].addActionListener(new ButtonListener(row, col));
	                buttons[row][col].setEnabled(true);

	                boardPanel.add(buttons[row][col]);
	            }
	        }
		}
		
		// 새롭게 게임이 시작하면 텍스트를 빈칸으로 설정
		// 모든 칸이 설치할 수 있어야 함
		for (int row = 0; row < GRID_SIZE; row++) 
        {
            for (int col = 0; col < GRID_SIZE; col++) 
            {
                buttons[row][col].setText("");
                
                checkCanPlaced[row][col] = true;
            }
        }
    }
	
	// 배치를 막기 위한 함수
	public void SetBooleanPlacedQueen(int x, int y) 
	{
		// 가로 세로 배치막기
		for(int i = 0; i<GRID_SIZE; i++) 
		{
			checkCanPlaced[x][i] = false;
			checkCanPlaced[i][y] = false;
			System.out.println("[직선] 다음 칸을 막음 : (" + x + ", " + i + ")");
			System.out.println("[직선] 다음 칸을 막음 : (" + i + ", " + y + ")");
			buttons[x][i].setText("[X]");
			buttons[i][y].setText("[X]");
		}
		
		// 대각선 막기
		SetFalseDiagonal(x, y, 1, 1); 	// 오른쪽 아래로
		SetFalseDiagonal(x, y, 1, -1); 	// 오른쪽 위로
		SetFalseDiagonal(x, y, -1, 1);	// 왼쪽 아래로
		SetFalseDiagonal(x, y, -1, -1);	// 왼쪽 위로
	}

	public void SetBooleanPlacedBishop(int x, int y) 
	{
		SetFalseDiagonal(x, y, 1, 1); 	// 오른쪽 아래로
		SetFalseDiagonal(x, y, 1, -1); 	// 오른쪽 위로
		SetFalseDiagonal(x, y, -1, 1);	// 왼쪽 아래로
		SetFalseDiagonal(x, y, -1, -1);	// 왼쪽 위로
	}
	
	public void SetBooleanPlacedRook(int x, int y) 
	{
		// 가로 세로 배치막기
		for(int i = 0; i<GRID_SIZE; i++) 
		{
			checkCanPlaced[x][i] = false;
			checkCanPlaced[i][y] = false;
			System.out.println("[직선] 다음 칸을 막음 : (" + x + ", " + i + ")");
			System.out.println("[직선] 다음 칸을 막음 : (" + i + ", " + y + ")");
			buttons[x][i].setText("[X]");
			buttons[i][y].setText("[X]");
		}
	}
	
	private Piece CreatePiece(String pieceType) 
    {
        switch (pieceType) 
        {
            case "Queen":	return new Queen(this);
            case "Bishop":	return new Bishop(this);
            case "Rook":	return new Rook(this);
            default:		return null;
        }
    }


	private boolean CanPlace(Piece piece, int x, int y) 
    {
    	switch(piece.GetText())
		{	
		case "Queen":
			// 1. 가로 세로에 놓여져있는 말이 있는지?
			for(int i = 0; i<GRID_SIZE; i++) 
			{
				if(gameBoard[x][i] != null || gameBoard[i][y] != null) return false;
			}

			// 2. 대각선 체크, 네 개중 하나라도 false 이면 놓을 수 없음
			return CheckDiagonal(x, y, 1, 1) && CheckDiagonal(x, y, 1, -1) && CheckDiagonal(x, y, -1, 1) && CheckDiagonal(x, y, -1, -1);

		case "Bishop":
			// 1. 대각선 체크, 네 개중 하나라도 false 이면 놓을 수 없음
			return CheckDiagonal(x, y, 1, 1) && CheckDiagonal(x, y, 1, -1) && CheckDiagonal(x, y, -1, 1) && CheckDiagonal(x, y, -1, -1);
			
		case "Rook":
			// 1. 가로 세로에 놓여져있는 말이 있는지?
			for(int i = 0; i<GRID_SIZE; i++) 
			{
				if(gameBoard[x][i] != null || gameBoard[i][y] != null) return false;
			}
			return true;
					
		}
    	return false; // 기본값은 그냥 false 처리
    }
    
    // 체스판에서 칸 클릭 리스너
    class ButtonListener implements ActionListener 
    {
        private int row, col;

        public ButtonListener(int row, int col) 
        {
            this.row = row;
            this.col = col;
        }

        @Override
        public void actionPerformed(ActionEvent e) 
        {
            if (currentPiece == null) 
            {
                JOptionPane.showMessageDialog(null, "말을 먼저 뽑아주세요.");
                return;
            }
            else if (gameBoard[row][col] == null && checkCanPlaced[row][col] == true && CanPlace(currentPiece, row, col)) 
            {
                gameBoard[row][col] = currentPiece;
                currentPiece.SetCannotPlaceCells(row, col);
                buttons[row][col].setText(currentPiece.GetText());
                buttons[row][col].setEnabled(true);
                buttons[row][col].repaint();
                System.out.println(currentPiece.GetText());
                score++;
                currentPiece = null;
                
                // 배치한 이후 게임이 끝났는지 Check
                CheckGameFinished();
            } 
            else 
            {
            	// 팝업
                JOptionPane.showMessageDialog(null, "여기엔 설치할 수 없습니다.");
            }
        }
    }
    
    class PieceButtonListener implements ActionListener 
    {
    	
        @Override
        public void actionPerformed(ActionEvent e) 
        {
        	if(gameEnd) 
        	{
        		RestartGame();
        	}
        	else if(currentPiece != null) 
        	{
        		JOptionPane.showMessageDialog(null, "아직 배치를 하지 않았습니다. 현재 말 : " + currentPiece.GetText());
        		return;
        	}
        	else 
        	{
        		 // 랜덤으로 말 선택
                int randomIndex = rand.nextInt(canPlacePieces.length);
                
                String selectedPiece = canPlacePieces[randomIndex];
                currentPiece = CreatePiece(selectedPiece);  // 선택된 말 객체 생성
                
                // 게임이 끝나지 않았을 때만 다음 말이 무엇인지 알림
                if(CheckGameFinishedDraw(currentPiece) == false) 
                {
                	// 팝업
                	JOptionPane.showMessageDialog(null, "다음 말 : " + selectedPiece);
                }
        	}
        }
    }
    
    private boolean CheckGameFinishedDraw(Piece piece) 
	{
		// 1. 빈 공간 탐색
		for(int x = 0; x<GRID_SIZE; x++) 
		{
			for(int y = 0; y<GRID_SIZE; y++) 
			{	
				if(gameBoard[x][y] == null && checkCanPlaced[x][y] == true) 
				{
					// Place 가능한 공간이 있다면 함수 탈출
					if(CanPlace(piece, x, y) == true) return gameEnd = false;
				}
			}
		}
		
		// 2. for 문이 종료됨 -> 설치할 수 있는 공간이 없다는 의미, 게임 종료
		JOptionPane.showMessageDialog(null, String.format("게임 종료, 최종 스코어 : %d", score));
		pieceButton.setText("다시하기");
		frame.setTitle(String.format("Puzzle Game | 최종 스코어 : %d", score));
		return gameEnd = true;
	}
	
	
	
	// 대각선 막는 함수
	private void SetFalseDiagonal(int x, int y, int dX, int dY) 
	{
		int newX = x + dX;
		int newY = y + dY;
		
		while(newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) 
		{
			checkCanPlaced[newX][newY] = false;
			buttons[newX][newY].setText("[X]");
			System.out.println("다음 칸을 막음 : (" + newX + ", " + newY + ")");
			newX += dX;
			newY += dY;
		}
	}
	
	// 대각선에 말이 있는지 체크
	private boolean CheckDiagonal(int x, int y, int dX, int dY) 
	{
		int newX = x + dX;
		int newY = y + dY;
		
		while(newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) 
		{
			if(gameBoard[newX][newY] != null) return false;
			newX += dX;
			newY += dY;
		}
		
		return true;
	}
}
