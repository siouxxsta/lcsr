#Requires -Version 7.6

param(
  [Parameter(Mandatory)]
  [string] $OutputFile
)
 
Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
 
Set-Location -LiteralPath (Split-Path $PSScriptRoot -Parent)
 
$hash = ''
if (Get-Command git -ErrorAction SilentlyContinue) {
  $hash = & git rev-parse --short HEAD 2>$null
  if ($LASTEXITCODE -ne 0) { $hash = '' }
}
 
Set-Content -LiteralPath $OutputFile -Encoding ascii -Value @(
  "#define GIT_SHA1 `"$hash`""
  'const char* g_GIT_SHA1 = GIT_SHA1;'
)
 