# view vrml
## what is this?
this is a sample of vrml.
vrml format is a format for 3d modeling.

## view vrml

install [view3dsecene](http://castle-engine.sourceforge.net/view3dscene.php)

```
tar zxvf view3dscene-3.15.0-linux-x86_64.tar.gz
cd view3dscene
view3dscene path/to/xxx.wrl
```

## vrml syntax
Following links may help you.<br>
[VRML](http://www.k.hosei.ac.jp/~sawa/lecture/vrml_nt/vrml_gr/vrml_kozo.html)

### format
simplest example:
```vrml
nodeName {
  fieldName fieldValue # field1
  fieldName fieldValue # field2
}
```


### DEF/USE
define node by DEF, and use copy of the node by USE.

sample:
```vrml
Shape { geometry  DEF NewBox Box {  } }
       ：
Shape { geometry USE NewBox }
```
*instead of*
```vrml
Shape { geometry  Box { ... } }
       ：
Shape { geometry  Box { ... } }
```

### PROTO
define new node by PROTO

example:
```
PROTO NewNodeName
  [
     attributeName  TypeName  FieldName  (DefaultValue)
                       :
  ]
  { DefinitionOfNode }
```
Using PROTO sample is soccor_PROTO.wrl.


### type of field
there are two type of fields:
- Single-valued fields and events (SF**)
- Multiple-valued fields and events (MF**)

example:
- 1.0 is SFFloat
- 1.0 2.0 3.0 is SFVec3f
- [0.1 0.2 0.3] may be MFColor
## vrml:Shape
under construction.
## vrml:Transform Node
### prototype of transform node
```
Transform {
  eventIn      MFNode      addChildren
  eventIn      MFNode      removeChildren
  exposedField SFVec3f     center           0 0 0
  exposedField MFNode      children         []       # children shape nodes
  exposedField SFRotation  rotation         0 0 1 0  # axis (in local coords) and angle
  exposedField SFVec3f     scale            1 1 1    # expand coords
  exposedField SFRotation  scaleOrientation 0 0 1 0  # scale by rotated coords (used with scale)
  exposedField SFVec3f     translation      0 0 0    # translate self origin from parent coords
  field        SFVec3f     bboxCenter       0 0 0
  field        SFVec3f     bboxSize         -1 -1 -1
}
```
