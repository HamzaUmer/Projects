//Design Module
module Garage_Door_System(motor_up,motor_down,Activate,Inside_up_button,Inside_down_button,Outside_up_button,Outside_down_button);
input Activate,Inside_up_button,Inside_down_button,Outside_up_button,Outside_down_button;
output motor_up,motor_down;
wire out1,out2,a1,a2;
or o1(out1,Inside_up_button,Outside_up_button);
or o2(out2,Inside_down_button,Outside_down_button); 
and an1(motor_up,Activate,out1,a1);
and an2(motor_down,Activate,out2,a2);
not n1(a1,motor_down);
not n2(a2,motor_up);
endmodule
//Stimullux Module
module HHUA;
reg  Activate,Inside_up_button,Inside_down_button,Outside_up_button,Outside_down_button;
wire motor_up,motor_down;
Garage_Door_System g1(motor_up,motor_down,Activate,Inside_up_button,Inside_down_button,Outside_up_button,Outside_down_button);
initial 
begin
Activate=1'b1; Inside_up_button=1'b0; Outside_up_button=1'b0; Inside_down_button=1'b0; Outside_down_button=1'b0;
#50
Activate=1'b1; Inside_up_button=1'b1; Outside_up_button=1'b0; Inside_down_button=1'b0; Outside_down_button=1'b0;
#50
Activate=1'b1; Inside_up_button=1'b0; Outside_up_button=1'b0; Inside_down_button=1'b0; Outside_down_button=1'b1;
#50
Activate=1'b1; Inside_up_button=1'b0; Outside_up_button=1'b1; Inside_down_button=1'b0; Outside_down_button=1'b0;
#50
Activate=1'b1; Inside_up_button=1'b0; Outside_up_button=1'b0; Inside_down_button=1'b1; Outside_down_button=1'b0;
#50
Activate=1'b0; Inside_up_button=1'b0; Outside_up_button=1'b0; Inside_down_button=1'b0; Outside_down_button=1'b0;
#50
$finish;
end 
endmodule