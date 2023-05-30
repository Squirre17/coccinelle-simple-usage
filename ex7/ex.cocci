@initialize:python@
@@
#-----------------------------Post Matching Process------------------------------

count = 0

def print_and_log(filename, first, second, count):
	print "No. ", count, " file: ", filename
	print "--first fetch: line ",first
	print "--second fetch: line ",second
	print "------------------------------------\n"

	logfile = open('result.txt','a')
	logfile.write("No." + count + " File: \n" + str(filename) + "\n")
	logfile.write("--first fetch: line " + str(first) + "\n")
	logfile.write("--second fetch: line " + str(second) + "\n")
	logfile.write("-------------------------------\n")
	logfile.close()

    
@ rule1 disable drop_cast exists @
expression addr,exp1,exp2,src,size1,size2,offset;
position p1,p2;
identifier func;
type T1,T2;
@@
    func(...){
    ...	
(
    copy_from_user(exp1, (T1)src, size1)@p1
|
    copy_from_user(exp1, src, size1)@p1
)
    ...	when any
        when != src += offset	
        when != src = src + offset
        when != src++
        when != src -=offset
        when != src = src - offset
        when != src--
        when != src = addr
        
(
    copy_from_user(exp2, (T2)src, size2)@p2
|
    copy_from_user(exp2, src, size2)@p2
)
    ...
}

@script:python@
p11 << rule1.p1;
p12 << rule1.p2;
s1  << rule1.src; // "src_buf" i.e. varname
@@

print "[+] rule1's src variable name :", str(s1)

if p11 and p12:
    print p11[0]
    print "[+] %s:%s %s" %(p11[0].file, p11[0].line, "rule1 1st fetch")
    print "[+] %s:%s %s" %(p12[0].file, p12[0].line, "rule1 2nd fetch")