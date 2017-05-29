# adhesive.py
import subprocess
import re
class a:
    def __init__(self):
        self.bindlist = {}
    def call(self,func,lang):
        res = subprocess.check_output(['./adhesive','call',func, lang])
        return_val = re.search('_ADHESIVERETURN:\({\[(.+)\]}\)',res).group(1)
        return return_val
    def handle(self,args):
        if "___adhescall" in args:
            # an adhesive function must be called
            if not self.bindlist[args[2]]:
                print "ADHESERROR: Function not binded"
            else:
                print "_ADHESIVERETURN:([{" + self.bindlist[args[2]]() + "}])"
                exit()
    def bind(self,bindword,func):
        self.bindlist[bindword] = func