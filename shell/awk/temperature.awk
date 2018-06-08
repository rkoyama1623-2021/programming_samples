{
    print NR ":" $0
    len=split($0, array, " ")
    for (i = 1; i <= NF; i++)
    {
        if ( $1=="Physical" && $(i-1)=="0:" && match($i, /^+[0-9][0-9].[0-9]/) ) {
            print "<<<< found"
            print substr($i, RSTART, RLENGTH)
            print ">>>>"
        }
    }
}
