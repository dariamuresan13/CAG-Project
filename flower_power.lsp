(defun c:floare()
   (setq color (getint "\nEnter index for the color you want: 4-blue, 40-orange, 211-pink "))
  
   (if (and (> color 0) (<= color 255))
    (progn

           (setq ss (ssget "X" (list (cons 62 color))))
      
          (if ss
        (progn
          
          
                   (setq center (getpoint "\nSelect center for the flower: "))
          
          (setq objCount (sslength ss))
          
          (setq ang 0)
          (setq incrementAngle 75)          
          (setq i 0)
          (while (< i objCount)
            (setq obj (ssname ss i))            
	            (setq objCoords (cdr (assoc 10 (entget obj))))
            
            (command "_.move" obj "" "_non" objCoords "_non" center)
          
            
            (command "_.rotate" obj "" "_non" center ang)
            
            (setq ang (+ ang incrementAngle))
            
            (setq i (1+ i))
          )
          
          (princ " Flower shape <3.")
        )
        (princ "\nNo objects found with the specified color.")      )
    )
    (princ "\nInvalid color index. Please enter a value between 0 and 255.")   )
  (princ) 
)
