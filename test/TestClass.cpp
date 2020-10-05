
#define LiquidCrystal_Test LiquidCrystal
#include "Common.cpp"

unittest(testingClassName) {
  LiquidCrystal_Test lcd(rs, enable, d4, d5, d6, d7);
  assertEqual("LiquidCrystal_CI", lcd.className());
}

unittest(getRows) {
  LiquidCrystal_Test lcd(rs, enable, d4, d5, d6, d7);
  assertEqual(1, lcd.getRows());
  lcd.begin(16, 2);
  assertEqual(2, lcd.getRows());
}

unittest(writeHigh) {
  // create lcd object
  LiquidCrystal_Test lcd(rs, enable, d4, d5, d6, d7);
  lcd.begin(16, 2);
  // get currently displayed lines
  std::vector<std::string> lines = lcd.getLines();
  // verify that display contains 2 empty lines
  assertEqual(2, lines.size());
  assertEqual(0, lines.at(0).length());
  assertEqual(0, lines.at(1).length());

  // Write stuff
  lcd.write('A');

  // Testing one character
  lines = lcd.getLines();
  std::cout << std::endl << lines.at(0) << std::endl;
  assertEqual(2, lines.size());
  assertEqual(1, lines.at(0).length());
  assertEqual("A", lines.at(0));
  assertEqual('A',lines.at(0).at(0));
  assertEqual(0, lines.at(1).length());

  // testing multiple character inputs
  lcd.write('u');
  lcd.write('s');
  lcd.write('t');
  lcd.write('i');
  lcd.write('n');
  lines = lcd.getLines();
  assertEqual(2, lines.size());
  assertEqual(6, lines.at(0).length());
  assertEqual("Austin", lines.at(0));
}

unittest(clearBuffer) {
  // create lcd object
  LiquidCrystal_Test lcd(rs, enable, d4, d5, d6, d7);
  // get currently displayed lines
  std::vector<std::string> lines = lcd.getLines();
  // verify that display contains 1 empty line
  assertEqual(1, lines.size());
  assertEqual(0, lines.at(0).length());

  // reset lcd to have two lines
  lcd.begin(16, 2);
  // verify that begin clears the display
  lines = lcd.getLines();
  // verify that display contains 2 empty lines
  assertEqual(2, lines.size());
  assertEqual(0, lines.at(0).length());
  assertEqual(0, lines.at(1).length());

  // write something to display
  lcd.print("hello world");

  // verify display not empty
  lines = lcd.getLines();
  assertEqual(2, lines.size());
  // assertEqual(11, lines.at(0).length());
  // assertEqual("hello world", lines.at(0));
  assertEqual(0, lines.at(1).length());

  // clear display
  lcd.clear();

  // verify display is empty
  lines = lcd.getLines();
  assertEqual(2, lines.size());
  assertEqual(0, lines.at(0).length());
  assertEqual(0, lines.at(1).length());
}

unittest_main()
