import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';

class diceRolling extends StatefulWidget {
  const diceRolling({super.key});

  @override
  State<diceRolling> createState() => _diceRollingState();
}

class _diceRollingState extends State<diceRolling> {
  int rightDice = 1;
  int leftDice = 5;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.red,
        title: Center(
          child: Text(
            "Dice Rolling App",
            style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
          ),
        ),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Center(
            child: Row(
              children: [
                Expanded(
                    child: Padding(
                  padding: const EdgeInsets.all(3),
                  child: GestureDetector(
                      onTap: () {
                        clickDice();
                      },
                      child: Image.asset("images/dice$leftDice.png")),
                )),
                Expanded(
                    child: Padding(
                  padding: const EdgeInsets.all(3),
                  child: GestureDetector(
                      onTap: () {
                        clickDice();
                      },
                      child: Image.asset("images/dice$rightDice.png")),
                )),
              ],
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(top: 30),
            child: Text(
              "Keep trying",
              style: TextStyle(
                  fontWeight: FontWeight.bold,
                  fontSize: 40,
                  color: Colors.deepPurple),
            ),
          ),
        ],
      ),
    );
  }

  clickDice() {
    setState(() {});
    int count = 0;
for(;;){

    rightDice = Random().nextInt(6) + 1;
    leftDice = Random().nextInt(6) + 1;
  if(rightDice != leftDice)
    count = count + 1;
  else{
    print("You WIN in ${count + 1} tryings");
    return 0;
  }
}
   
  }
}
