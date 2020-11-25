function love.load()
	--local myFont = love.graphics.newFont(45)
	love.graphics.setFont(love.graphics.newFont(45))
	love.graphics.setColor(0,0,0,255)
	love.graphics.setBackgroundColor(255,153,0)
end

function love.update(dt)
end

function love.draw()
--the text and position
love.graphics.print('Hellow world', 200,500)
end
