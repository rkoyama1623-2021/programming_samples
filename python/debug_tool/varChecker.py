class varChecker():
    def varName(self,var,symboltable):
        for k,v in symboltable.iteritems():
            if id(var)==id(v) and k != 'var':
                return k
    def varInfo(self,var,symboltable):
        print '[',self.varName(var,symboltable),']',type(var),'/',var
