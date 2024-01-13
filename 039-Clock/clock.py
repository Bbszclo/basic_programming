class MyClock24:
    """
    Expose a @property for hours, minutes, seconds. 
    You may implement additional @property and @property_name.setter  methods as needed
    Implement a tick() method that advances the clock one second.
    Implement a __str__ method that prints the time in this format: HH:MM:SS
    Implement a __repr__ method that prints out the hour, minute, and second attributes as a dictionary literal.
    Implement the magic methods for eq, ne, ge, gt,le,lt. Use the comparison of the full time for these methods.
    Implement the magic methods for add and sub. You either accept another MyClock24 object as the second parameter or an int that represents the number  of ticks to move the clock forward or back.
    Note: If the time goes outside of the range of 00:00:00 to 23:59:59, then the time should roll over / roll back as appropriate.
    """
    SECONDS_IN_DAY = 24 * 60 * 60
    _ticks = 0

    def __init__(self, hours, minutes, seconds):
        if type(hours) is not int or type(minutes) is not int or type(seconds) is not int:
            raise ValueError("hours, minutes and seconds must all be integers")
        if hours < 0 or hours > 23:
            raise ValueError("Input out of the range 0-23:" + str(hours))
        if minutes < 0 or minutes >59:
            raise ValueError("Input out of the range 0-59:" + str(minutes))
        if seconds < 0 or seconds >59:
            raise ValueError("Input out of the range 0-59:" + str(seconds))

        self.ticks = hours * (60*60) + (minutes * 60) + seconds

    def __repr__(self):
        return str({"hours": self.hours, "minutes":self.minutes, "seconds":self.seconds})
    
    def __str__(self):
        return "{:0>2d}:{:0>2d}:{:0>2d}".format(self.hours, self.minutes, self.seconds)
    
    @property
    def hours(self):
        return int(self._ticks // (60 * 60))
    
    @property
    def minutes(self):
        result = int(self._ticks) % (60*60)
        return result // 60
    
    @property
    def seconds(self):
        return self._ticks % 60
    
    @property
    def ticks(self):
        return self._ticks
    
    @ticks.setter
    def ticks(self, new_ticks):
        self._ticks = new_ticks % self.SECONDS_IN_DAY
    
    def tick(self):
        self.ticks = self.ticks + 1
    
    def __eq__(self,other):
        return self.ticks == other.ticks
    
    def __ne__(self,other):
        return self.ticks != other.ticks

    def __ge__(self,other):
        return self.ticks >= other.ticks
    
    def __gt__(self,other):
        return self.ticks > other.ticks
    
    def __le__(self,other):
        return self.ticks <= other.ticks

    def __lt__(self,other):
        return self.ticks < other.ticks

    def __add__(self,other):
        result = MyClock24(0,0,0)
        if type(other) is int:
            result.ticks = self.ticks + other
        else:
            result.ticks = self.ticks + other.ticks
        return result
        
    
    def __sub__(self,other):
        result = MyClock24(0,0,0)
        if type(other) is int:
            result.ticks = self.ticks - other
        else:
            result.ticks = self.ticks - other.ticks
        return result
