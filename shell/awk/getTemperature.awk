NR==3 && match($4, /[0-9][0-9].[0-9]/) { print substr($4, RSTART, RLENGTH) }
