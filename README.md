# line_follower_robot

## What’s a Line Follower Robot?
  Imagine a little robot with “eyes” that can see a path on the floor — usually a black line on a white background. The robot’s job? To follow that line smoothly and accurately,
like how you might walk along a painted path in a park.

## How Does It Work?
  The robot uses two tiny sensors — kind of like its eyes — placed on the bottom front, on the left and right sides. These sensors can tell if they’re over the dark line or the white floor by sensing light intensity.
  When both sensors see black (the line), the robot moves straight ahead.
  If the left sensor moves off the line and sees white, the robot knows it’s drifting left — so it gently turns right to get back on track.
  Similarly, if the right sensor loses the line, the robot corrects by turning left.

## How Does the Robot Decide Which Way to Turn?
  Think of it like how you balance when walking on a narrow path: if you start to drift to one side, you naturally adjust your steps to stay on the line.
  The robot does the same using a method called PID control — which stands for Proportional, Integral, Derivative. It’s a fancy way of saying:
    Proportional: “Hey, I’m a little off — let me correct a bit.”
    Integral: “I’ve been off for a while — I need to correct more.”
    Derivative: “My error is changing fast — better adjust quickly.”
  This math helps the robot make smooth, smart adjustments rather than jerky movements, so it follows the line naturally.

## Why Use Two Sensors?
  With two sensors instead of one, the robot has a better idea of which side it’s drifting towards.
  It’s like having depth perception — helping it stay centered and react quickly when the path curves or splits.

## What Powers the Robot?
  Inside, it has small motors that move its wheels. The robot’s “brain” (the Arduino) tells these motors how fast and in what direction to spin, based on what the sensors see.
  The motors make the wheels turn forward, backward, or slow down one side — all to keep the robot hugging the line perfectly.
