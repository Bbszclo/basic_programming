import unittest
from max_seq import max_seq

class TestMaxSeq(unittest.TestCase):

    def test_empty_list(self):
        list1 = max_seq([])
        self.assertEqual(list1, []) 
    
    def test_increasing_list(self):
        list2 = max_seq([1,2,3,4,5])
        self.assertEqual(list2,[1,2,3,4,5])
    
    def test_descresing_list(self):
        list3 = max_seq([5,4,3,2,1])
        self.assertEqual(list3,[5])

    def test_mix_sequence(self):
        list4 = max_seq([1,2,3,4,2,3,4,5,6,7,1,2])
        self.assertEqual(list4,[2,3,4,5,6,7])
    
    def test_bad_list(self):
        with self.assertRaises(Exception) as context:
            max_seq([ 1,2.2, "string",3])
        self.assertTrue(type(context.exception) == TypeError,"Wrong type raised")

if __name__ == '__main__':
    unittest.main(argv=['unittest','TestMaxSeq'])