Write-Host "Cloning SDL..."
git clone https://github.com/libsdl-org/SDL.git

Write-Host "Cloning SDL_image..."
git clone https://github.com/libsdl-org/SDL_image.git

Write-Host "Cloning SDL_ttf..."
git clone https://github.com/libsdl-org/SDL_ttf.git

Write-Host "Cloning Dependencies for SDL_image..."
& ".\SDL_image\external\Get-GitModules.ps1"

Write-Host "Cloning Dependencies for SDL_ttf..."
& ".\SDL_ttf\external\Get-GitModules.ps1"

Write-Host "Succeeded!"