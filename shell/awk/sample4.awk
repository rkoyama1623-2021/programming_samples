aBEGIN {
    couont = 0
    print "start script"
}
{ print $0 }
count > 4 { printf("\tcount is larger than 4 ( %d ) \n", count) }
{ count += 1 }

