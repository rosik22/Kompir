local angle = 0
local height = 10
local width = 10

function love.load()
	love.graphics.setColor(0,0,0,255)
	love.graphics.setBackgroundColor(255,153,0)
end

function love.draw()
	love.graphics.rotate(angle)
	love.graphics.setColor(0,0,0)
	love.graphics.rectangle("fill",600,400,width,height)
	love.graphics.rectangle("fill",400,300,width*2,height*2)
end

function love.update(dt)
	if love.keyboard.isDown("d") then
		angle=angle+math.pi*dt
	elseif love.keyboard.isDown("a") then
		angle=angle-math.pi*dt
	end
end
