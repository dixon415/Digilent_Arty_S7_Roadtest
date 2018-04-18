`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01.04.2018 14:50:03
// Design Name: 
// Module Name: blinky
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module blinky(
    input clk,
    output led,
    input sw
    );
    reg [24:0] count = 0;  
    assign led = count[24];
    always @ (posedge(clk)) count <= count + 1;
endmodule
