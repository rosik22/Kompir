function printlist(p)
    s = 10
    while s~=0 do
      print(p.data)
      p = p.next
      s = s-1
    end
  end

function reverselist(p, first)
    local q = first
    while p~=nil do
      local k = q
      q = p
      p = p.next
      q.next = k
    end
    return q
end

p = nil
k = 0
for s in io.lines("1.txt") do
    p = {data = s, next = p}
    if k == 0 then
        first = p
        k = k+1
    end
end

p = reverselist(p,first)
printlist(p)
print(p.last)