import unittest
from credit_card import validate

class TestCreditCardValidator(unittest.TestCase):
    """
    Tests a credit card number validator
        
    Validates whether or not a card_number represents a potentially valid
    credit card number.
    Card numbers must be strings composed of ASCII numbers (0-9) meeting these
    rules:
      - Visa cards: starts with the digit 4, length 16
      - Mastercard: starts with 51-55  and 2221-2720, length 16
      - American Express:  starts with 34 or 37, length 15
      - Number must pass the Luhn checksum
    Args:
    card_number(str): credit card number to validate
    returns:
    True if the card_number is valid, False others

    """


    def test_valid_visa(self):
        """Ensures a valid visa number passes"""
        self.assertTrue(validate("4263982640269299"))
    
    def test_invalid_visa_luhn(self): #test for Luhn for visa
        self.assertFalse(validate("4263982640269298"))
    
    def test_invalid_visa_length(self):
        self.assertFalse(validate("42639826402692990"))
    
    def test_invalid_visa_shortest(self):
        self.assertFalse(validate("4"))
    
    def test_invalid_visa_preflix(self):
        self.assertFalse(validate("5263982640269299"))

    def test_valid_mastercard(self):
        """Ensures a valid mastercard number passes
            Mastercard: starts with 51-55  and 2221-2720, length 16
        """
        self.assertTrue(validate("5425233430109903"))
    
    def test_invalid_mastercadr_preflix(self):
        self.assertFalse(validate("5025233430109903"))
    
    def test_invalid_mastercard_preflix2(self):
        self.assertFalse(validate("5525233430109903"))

    def test_valid_mastercard_preflix(self):
        self.assertTrue(validate("5125233430109903"))

    def test_valid_mastercard_preflix2(self):
        self.assertTrue(validate("5525233430109903"))
    
    def test_valid_mastercard_preflix3(self):
        self.assertTrue(validate("2221233430109903"))
    
    def test_valid_mastercard_preflix4(self):
        self.assertTrue(validate("2720233430109903"))
    
    def test_valid_mastercard_preflix5(self):
        self.assertTrue(validate("2222233430109903"))
    
    def test_valid_mastercard_preflix6(self):
        self.assertTrue(validate("2719233430109903"))
    
    def test_invalid_mastercard_preflix3(self):
        self.assertFalse(validate("2220233430109903"))
    
    def test_invalid_mastercard_preflix4(self):
        self.assertFalse(validate("2721233430109903"))



    def test_valid_american_express(self):
        """Ensures a valid american express number passes"""
        self.assertTrue(validate("374245455400126")) 
    
    def test_invalid_american_express_long(self):
        self.assertFalse(validate("3742454554001260")) 
    
    def test_invalid_american_express_short(self):
        self.assertFalse(validate("37424545540012")) 
    
    def test_invalid_american_express_preflix(self):
        self.assertFalse(validate("354245455400126")) 
    
    def test_invalid_american_express_preflix2(self):
        self.assertFalse(validate("384245455400126")) 

    def test_invalid_american_express(self):
        """Ensure an invalid american express number fails"""
        self.assertFalse(validate("377024907644532"))                   

    def test_invalid_anytyoecard(self):
        self.assertFalse(validate("657024907644532"))   

if __name__ == '__main__':
    unittest.main(argv=['unittest','TestCreditCardValidator'], verbosity=2, exit=False)