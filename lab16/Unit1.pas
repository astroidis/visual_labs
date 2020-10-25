unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, VclTee.TeeGDIPlus, VCLTee.TeEngine,
  VCLTee.Series, Vcl.ExtCtrls, VCLTee.TeeProcs, VCLTee.Chart, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Chart1: TChart;
    Series1: TLineSeries;
    Series2: TLineSeries;
    Series3: TLineSeries;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
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
begin
  Close();
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  x, step, stop, y: real;
begin
  x := 1;
  stop := 10;
  step := 0.1;

  while x <= stop + step/2 do
  begin
    y := 2.5 * exp(x * ln(1.08));
    Series1.AddXY(x, y);

    y := 5.7 * exp(x * ln(1.095));
    Series2.AddXY(x, y);

    y := 5.7 * exp(x * ln(1.095)) + 5.45;
    Series3.AddXY(x, y);

    x := x + step;
  end;
end;

end.
