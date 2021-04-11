//hellolaunch

//First, we'll clear the terminal screen to make it look nice
clearScreen.

//This is our countdown loop, which cycles from 10 to 0
print "Counting down:".
from {local countdown is 10.} until countdown = 0 step {set countdown to countdown - 1.} do {
    print "..." + countdown.
    wait 1. //pauses the script here for 1 second.
}

until ship:maxthrust > 0 {
    wait 0.5. // pause half a second between stage attempts.
    print "Stage activated".
    stage.
}

wait until ship:altitude > 70000.

// NOTE that it is vital to not just let the script end right away
// here.  Once a kOS script just ends, it releases all the controls
// back to manual piloting so that you can fly the ship by hand again.
// If the program just ended here, then that would cause the throttle
// to turn back off again right away and nothing would happen.
