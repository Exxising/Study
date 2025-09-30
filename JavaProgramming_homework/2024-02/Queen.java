public class Queen extends Piece 
{
	public Queen() 
	{ 
		this.SetText("Queen");
	}
	
	public Queen(GameManager game) 
	{ 
		super(game);
		this.SetText("Queen");
	}
	
	// 놓은 칸을 기준으로 놓을 수 없는 칸 계산
	@Override
	public void SetCannotPlaceCells(int x, int y) 
	{
		game.SetBooleanPlacedQueen(x, y);
	}
}
