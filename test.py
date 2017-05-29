# test.py
import sys
import adhesive as adhes
def other_thing():
    return "hello?"
adhesiv = adhes.a()
adhesiv.bind("other_thing",other_thing)
adhesiv.handle(sys.argv)
#print adhesiv.call("thing","cpp")