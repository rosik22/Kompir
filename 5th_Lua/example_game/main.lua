function love.load()
	g = love.graphics
	playerColor = {255,0,128}
	groundColor = {25,200,25}
	
	xPos = 300
	yPos = 300
	playerWidth = 25
	playerHeight = 40
	
	xVelocity = 0
	yVelocity = 0
	playerState = "jump"
	
	playerJumpVelocity = -800
	runSpeed = 500
	gravity = 1800
	yFloor = 500
end

function love.update(dt)
	if love.keyboard.isDown("right") then
		xVelocity = runSpeed
	end
		
	if love.keyboard.isDown("left") then
		xVelocity = -1*runSpeed
	end
	
	if not(playerState == "jump") and love.keyboard.isDown("x") then
		yVelocity = playerJumpVelocity
		playerState = "jump"
	end
	
	xPos = xPos + (xVelocity * dt)
	yPos = yPos + (yVelocity * dt)
	yVelocity = yVelocity + (gravity * dt)
	
	if yPos >= yFloor - playerHeight then
		yPos = yFloor - playerHeight
		yVelocity = 0
		playerState = "stand"
	end
end

function love.draw()
	g.setColor(playerColor)
	g.rectangle("fill",xPos,yPos,playerWidth,playerHeight)
	g.setColor(groundColor)
	g.rectangle("fill",0,yFloor,1100,100)
end

function love.keyreleased(key)
	if key=="escape" then
		love.event.push("q")
	end
	
	if(key=="right") or (key=="left") then
		xVelocity = 0
	end
end
