Begin

Create function naiveAlgo(text,pattern)

SET Size of the string  = n
SET Size of the pattern = m
SET patternMachingTime = 0

For i in range n:
	For j in range m:
		If pattern[j] = text[j] for both capital and simple letter then
            i++
            patternMachingTime++
        end If
        Else If pattern[j] != text[j] for both capital and simple letter then
            patternMachingTime = 0
            break;
        end Else If 
    end For

    If patternMachingTime = m then
        break;
    end If

End For

End function

End

    
	
