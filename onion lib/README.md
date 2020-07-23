# i2c-exp-driver
Project for drivers to program Omega Expansions that are I2C-based.

# ubus Integration
The drivers for the I2C-based Onion Expansions have been integrated with the ubus service via RPCD. They can be accessed through the i2c_exp service.


[//]: # (pwm-exp)

## pwm-exp ubus Commands
The Servo Expansion can be programmed using the `pwm-exp` command in the i2c_exp ubus service:
```bash
ubus call i2c_exp pwm-exp '{"command":"String", "params": {"key": "value" } }'
```

The following commands are available:
* init
* sleep
* set
* set-period


[//]: # (pwm-exp: init)

### Init Command
The `init` command will reset the chip on the Servo Expansion and enable the oscillator.
```bash
ubus call i2c_exp pwm-exp '{"command":"init"}'
```

[//]: # (pwm-exp: sleep)

### Sleep Command
The `sleep` command will put the oscillator into sleep mode, disabling all PWM signals
```bash
ubus call i2c_exp pwm-exp '{"command":"sleep"}'
```

[//]: # (pwm-exp: set)

### Set Command
The `set` command is used to generate a PWM signal on a specific channel based on a **duty cycle percentage**:
```bash
ubus call i2c_exp pwm-exp '{"command":"set", "params":{"channel":"<CHANNEL>", "duty":"<DUTY CYCLE>"} }'
```

The CHANNEL can be:
* 0 - 15
  * control an individual channel
* all
  * control all channels at once

The DUTY CYCLE can be an integer or **floating point** number between 0 and 100

Optional parameters:
* `"frequency":"<signal frequency>"`
  * Sets the PWM signal frequency
  * If not specified, default of 50 Hz is used
  * Frequency range is 24 Hz to 1526 Hz
* `"delay":"<delay percentage>"`
  * Adds a delay in the PWM signal, can be an integer or **floating point** number between 0 and 100
  * 0% delay by default


[//]: # (pwm-exp: set-period)

### Set-Period Command
The `set-period` command is used to generate a PWM signal on a specific channel based on a **PWM period and pulse width** (both can be integer or floating point numbers):
```bash
ubus call i2c_exp pwm-exp '{"command":"set-period", "params":{"channel":9, "pulse":"1.5", "period":20}}'
```



[//]: # (relay-exp)

## relay-exp ubus Commands
The Relay Expansion can be programmed using the `relay-exp` command in the i2c_exp ubus service:


[//]: # (relay-exp: set)

### Set Command
The `set` command allows for programming the relay state:
```bash
ubus call i2c_exp relay-exp '{"command":"set", "params":{"channel":"<CHANNEL>", "state":"RELAY STATE", "address":"<ADDRESS>"}}'
```

The CHANNEL can be one of:
* 0		- controls Relay0
* 1		- controls Relay1
* all 	- controls both relays

The RELAY STATE can be one of:
* off	- relay is switched off
* on	- relay is switched on

The ADDRESS argument can be either:
* The DIP-SWITCH STATES 
* The Hex I2C device address

#### Dip Switch States
The DIP-SWITCH STATES should reflect the dip switch settings in binary starting with switch 1, then switch 2, then switch 3. The 0 position is when the switch is close the numbers.

Not required when all switches are 0.

Examples: 
* Switches 1 and 2 are 0 (close to the printed numbers), switch 3 is 1:
  * `"address":"001"`
* Switches 1 and 3 are 1, switch 2 is 0:
  * `"address":"101"`
* All switches are 1:
  * `"address":"111"`

#### I2C Device Address 
The I2C Device Address should be just the hex address.

For example:
* 0x27
* 0x23


[//]: # (relay-exp: get)

### Get Command
The `get` command implements reading the current state of a relay:
```bash
ubus call i2c_exp relay-exp '{"command":"get", "params":{"channel":"<CHANNEL>", "address":"<ADDRESS>"}}'
```

The CHANNEL can be one of:
* 0   - controls Relay0
* 1   - controls Relay1

The ADDRESS argument can be either:
* The DIP-SWITCH STATES 
* The Hex I2C device address

#### Dip Switch States
The DIP-SWITCH STATES should reflect the dip switch settings in binary starting with switch 1, then switch 2, then switch 3. The 0 position is when the switch is close the numbers.

Not required when all switches are 0.

Examples: 
* Switches 1 and 2 are 0 (close to the printed numbers), switch 3 is 1:
  * `"address":"001"`
* Switches 1 and 3 are 1, switch 2 is 0:
  * `"address":"101"`
* All switches are 1:
  * `"address":"111"`

#### I2C Device Address 
The I2C Device Address should be just the hex address.

For example:
* 0x27
* 0x23

### Return Values
The ubus call will return different values based on if the command was successful or not.

Successful Command:
```bash
{"status":"success", "channel":"<CHANNEL>, "state":"<RELAY STATE>"}
```

Unsuccessful Command:
```bash
{"status":"success", "error":"<INFO ON ERROR>"}
```


[//]: # (oled-exp)

## oled-exp ubus Commands
The OLED Expansion can be programmed using the `oled-exp` command in the i2c_exp ubus service:

### Set Command
The only command is the `set` command, it allows the relays to be programmed:
```bash
ubus call i2c_exp relay-exp '{"command":"set", "option":"opt" "params":{"<COMMAND>":"<COMMAND PARAMETER>}}'
```

[//]: # (oled-exp: options)

#### Options
Available options are
* i
  * Initialize the display, **this must be done at powerup**
* c
  * Clear the screen and set the cursor to the top left"

Example Usage:
* Initialize the display
  * `ubus call i2c_exp oled-exp '{"command":"set", "option":"i"}}'`
* Clear the display and then write Onion Omega to it
  * `ubus call i2c_exp oled-exp '{"command":"set", "option":"c", "params":{"write":"Onion Omega"}}'`


[//]: # (oled-exp: commands)

#### Commands
The following are the commands and their parameters as accepted by the oled-exp:
* `power <on|off>`
* `invert <on|off>`
* `dim <on|off>`
* `cursor <row>,<column>`
* `write <msg>`
* `scroll <direction>`
* `draw <lcd file>`

Commands can be strung together!

[//]: # (oled-exp: commands: power)

##### Power
Turn the display on or off. Can be used to toggle the display after it has been initialized.
```
"params":{"power":"<on|off>"}
```


[//]: # (oled-exp: commands: invert)

##### Invert
Invert black and white on the display. Setting to `on` will enable the invert, setting to `off` will disable the inversion.
```
"params":{"invert":"<on|off>"}
```


[//]: # (oled-exp: commands: dim)

##### Dim
Enable dimming the display. Setting to `on` will dim the display, setting to `off` will restore the default brightness.
```
"params":{"dim":"<on|off>"}
```


[//]: # (oled-exp: commands: cursor)

##### Cursor
Set the cursor position on the display. 

The `row` parameter represents each character row (8 pixel rows) on the display, so the range is **0 to 7**

The `column` parameter represents each character column, the range is **0 to 20**
```
"params":{"cursor":"<row>,<column>"}
```

###### Examples
Set the cursor to the start of the last character row:
```
"params":{"cursor":"7,0"}
```

Set the cursor to the middle of the 4th character row:
```
"params":{"cursor":"3,10"}
```

Set the cursor to the start of the 2nd character row:
```
"params":{"cursor":"1,0"}
```

Set the cursor to the top left (home position):
```
"params":{"cursor":"0,0"}
```


[//]: # (oled-exp: commands: write)

##### Write
Write a string to the display. 

```
"params":{"write":"<message>"}
```

###### Notes
To get a newline on the display, need to write `\\\\\n` in the message.

For now, avoid the following characters:
* `"`
* `'`


###### Examples
Write `Onion Omega` to the display:
```
"params":{"write":"Onion Omega"}
```

Write `Onion Corporation` and then the office address on the lines below:
```
"params":{"write":"Onion Corporation\\\\\n187 Denison St\\\\\nMarkham, ON\\\\\nCanada\\\\\nL3R-1B5"}
```


[//]: # (oled-exp: commands: scroll)

##### Scroll
Enable scrolling of whatever is currently on the display.

```
"params":{"scroll":"<direction>"}
```

###### Directions
Available directions:
* left
* right
* diagonal-left
* diagonal-right
* stop
  * To disable scrolling


[//]: # (oled-exp: commands: draw)

##### Draw
Display an image from an LCD file on the display. 

*Details on LCD file: The LCD file must be generated by the Onion utility. For a 128x64 image, there should be 1024 bytes. Each byte is one character column (8 vertical pixels), with the LSB representing the top-most pixel.*

```
"params":{"draw":"<path to lcd file>"}
```

  
