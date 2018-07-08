class LRUCache(object):


    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.store = {}
        self.usage = []
        self.max_cap = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.usage:
            return -1
        self.usage.remove(key)
        self.usage.append(key)
        return self.store.get(key)


    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.usage:
            self.usage.remove(key)
        elif len(self.usage) >= self.max_cap:
            del_key = self.usage[0]
            self.usage.remove(del_key)
        self.usage.append(key)
        self.store[key] = value



        # Your LRUCache object will be instantiated and called as such:
        # obj = LRUCache(capacity)
        # param_1 = obj.get(key)
        # obj.put(key,value)