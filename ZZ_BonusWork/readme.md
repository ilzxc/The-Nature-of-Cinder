### ZZ_BonusWork


#### /NessBox2D

Port of an old Processing sketch for making a spriteSheet character walk around with user input. (Arrow Keys, Left Shift to "run.")

#### /ParticleGrids

See [Hello Cinder Chapter 2](http://libcinder.org/docs/v0.8.5/hello_cinder_chapter2.html)

#### /SpinningBaton

See Shiffman's [Exercise 3.1](http://natureofcode.com/book/chapter-3-oscillation/)

#### /UnderstandingImages

A sandbox style project for messing about with image loading and subsets. (Will definitely change, as I have more things to try.)

#### /oscar

Uses OSC in Cinder to communicate with a Cycling 74 Max patch (found in _max subdirectory). For users without Max:

* ports: `2222` to send to Cinder; `2223` to receive from Cinder
* Cinder understands:
	* `/square/color float float float` bundle
	* `/square/rotation float` message
* Cinder sends:
	* `/fromCinder/MouseMove/X`
	* `/fromCinder/MouseMove/Y`
	* `/fromCinder/MouseDown/X`
	* `/fromCinder/MouseDown/Y`  