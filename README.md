Very simple program for arduino nano every, that is
sending data through various simple protocols, so you
can deploy it and check for basic communication with
logic analyzer or oscilloscope.

For checking it with logic analyzer / oscilloscope.
    
Via serial console first select protocol - "uart" / "spi" / "i2c",
then start the communication with sending "1". You can go
back and select different protocol by sending "back".
    
In uart, it sends numbers 0-9, in spi it sends string "sending spi"
and in i2c it scans all i2c slaves' addresses.
