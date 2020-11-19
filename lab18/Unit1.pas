unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Grids;

type
  TForm1 = class(TForm)
    StringGrid1: TStringGrid;
    Button1: TButton;
    Button2: TButton;
    Label1: TLabel;
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
const
  n = 5;
  x: array [1..n] of real = (0.2, 0.7, 1.8, 3.1, 4.2);

var
  i: integer;
begin
  for i := 1 to n do
  begin
    StringGrid1.Cells[0, i] := IntToStr(i) + ' item';
  end;
  StringGrid1.Cells[1, 0] := 'x';
  StringGrid1.Cells[2, 0] := 'cos(x)';

  for i := 1 to n do
  begin
    StringGrid1.Cells[1, i] := FormatFloat('0.0', x[i]);
    StringGrid1.Cells[2, i] := FormatFloat('0.000', cos(x[i]));
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Close();
end;

end.
