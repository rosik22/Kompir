function printlist(node)
    local it = node
	repeat
	    print(it.data)
	    it = it.next
    until it == node
        
end

function create(x)
    local t = {}
    t.data = x
    t.next = t
    t.prev = t
    return t
end

function insertlist(h,x)
    local k = create(x)
    k.next = h.next
    k.prev = h
    h.next = k
    return h
end

--въвежда стойност, за да не е празен листа
h = create(1)
h = insertlist(h,2)
h = insertlist(h,3)
h = insertlist(h,4)
printlist(h)