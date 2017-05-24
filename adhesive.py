# adhesive.py
import subprocess
class a:
    def __init__(self):
        self.bindlist = {}
    def call(self,func,lang):
        return subprocess.check_output(['./adhesive','call',func, lang])
    def handle(self,args):
        if "___adhescall" in args:
            # an adhesive function must be called
            if not self.bindlist[args[2]]:
                print "ADHESERROR: Function not binded"
            else:
                print "ADHES:([{" + self.bindlist[args[2]]() + "}])"
    def bind(self,func,bindword):
        self.bindlist[bindword] = func