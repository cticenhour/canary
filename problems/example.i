[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 20
  ymax = 20
[]

[Variables]
  [./u]
  [../]
[]

[Kernels]
  [./diff]
    type = ExampleDiff
    variable = u
  [../]
  [./reaction]
    type = Reaction
    variable = u
  [../]
[]

[BCs]
  [./neumann]
    type = FunctionNeumannBC
    variable = u
    function = 0.2
    boundary = 'left right top bottom'
  [../]
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
