void wheel(int left, int right)
{
  if (left == 1) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else  if (left == -1) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  else if (left == 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  if (right == 1) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else  if (right == -1) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else if (right == 0) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }


}
